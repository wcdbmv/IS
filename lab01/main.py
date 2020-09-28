#!/usr/bin/env python3

from installer import check_license


if __name__ == '__main__':
    if not check_license():
        raise Exception('License check fail')

    print('Thanks for buying license')
