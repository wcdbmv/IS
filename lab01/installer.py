#!/usr/bin/env python3

from sys import platform
from subprocess import check_output
from hashlib import sha256


LICENSE_FILE = 'license.key'


def hash(s: str) -> str:
    return sha256(s.encode()).hexdigest()


def check_output_str(args: str) -> str:
    return check_output(args, shell=True, text=True)[:-1]


def check_output_str_lower(args: str) -> str:
    return check_output_str(args).lower()


class Shell:
    get_hardware_uuid_commands = {
        'linux': 'dmidecode -s system-uuid',
        'darwin': "system_profiler SPHardwareDataType | awk '/Hardware UUID:/ {print $3}'",
        'win32': 'wmic csproduct get UUID',
    }

    get_system_serial_number_commands = {
        'linux': 'dmidecode -s system-serial-number',
        'darwin': "system_profiler SPHardwareDataType | awk '/Serial Number (system):/ {print $4}'",
        'win32': 'wmic csproduct get IdentifyingNumber',
    }


def get_computer_id() -> str:
    for prefix in ('linux', 'darwin', 'win32'):
        if platform.startswith(prefix):
            get_hardware_uuid_command = Shell.get_hardware_uuid_commands[prefix]
            get_system_serial_number_command = Shell.get_system_serial_number_commands[prefix]
            break
    else:
        raise Exception('Not supported platform')

    hardware_uuid = check_output_str_lower(get_hardware_uuid_command)
    system_serial_number = check_output_str(get_system_serial_number_command)

    return f'{hardware_uuid}:{system_serial_number}'


def get_computer_id_hash() -> str:
    return hash(get_computer_id())


def create_license() -> None:
    with open(LICENSE_FILE, 'w') as file:
        file.write(get_computer_id_hash())


def read_license() -> str:
    with open(LICENSE_FILE, 'r') as file:
        return file.read()


def check_license() -> bool:
    return read_license() == get_computer_id_hash()


if __name__ == '__main__':
    create_license()
