import argparse
from sys import exit
from typing import Tuple
from Crypto import Random
from Crypto.Hash import SHA256
from Crypto.PublicKey import RSA
from Crypto.Signature import pkcs1_15


def parse_args() -> argparse.Namespace:
    parser = argparse.ArgumentParser(prog='Digital Signature')
    subparsers = parser.add_subparsers(dest='mode', required=True, help='sub-command help')

    parser_keygen = subparsers.add_parser('keygen')
    parser_keygen.add_argument('pubkey_filename')
    parser_keygen.add_argument('prtkey_filename')

    parser_sign = subparsers.add_parser('sign')
    parser_sign.add_argument('filename')
    parser_sign.add_argument('prtkey_filename')
    parser_sign.add_argument('signature_filename')

    parser_check = subparsers.add_parser('check')
    parser_check.add_argument('filename')
    parser_check.add_argument('pubkey_filename')
    parser_check.add_argument('signature_filename')
    parser_check.add_argument('-q', '--quiet', action='store_true')

    return parser.parse_args()


def keygen() -> Tuple[bytes, bytes]:
    random_generator = Random.new().read
    key_pair = RSA.generate(2048, random_generator)
    return key_pair.publickey().export_key('PEM'), key_pair.export_key('PEM')


def sign(msg: bytes, prtkey: bytes) -> bytes:
    sha256_hash = SHA256.new(msg)
    signer = pkcs1_15.new(RSA.import_key(prtkey))
    signature = signer.sign(sha256_hash)
    return signature


def check(msg: bytes, pubkey: bytes, signature: bytes) -> bool:
    sha256_hash = SHA256.new(msg)
    verifier = pkcs1_15.new(RSA.import_key(pubkey))
    try:
        verifier.verify(sha256_hash, signature)
        return True
    except ValueError:
        return False


def read(filename: str) -> bytes:
    with open(filename, 'rb') as file:
        content = file.read()
    return content


def write(filename: str, content: bytes) -> None:
    with open(filename, 'wb') as file:
        file.write(content)


def main() -> None:
    args = vars(parse_args())

    if args['mode'] == 'keygen':
        pubkey, prtkey = keygen()
        write(args['pubkey_filename'], pubkey)
        write(args['prtkey_filename'], prtkey)

    elif args['mode'] == 'sign':
        msg = read(args['filename'])
        prtkey = read(args['prtkey_filename'])
        signature = sign(msg, prtkey)
        write(args['signature_filename'], signature)

    elif args['mode'] == 'check':
        msg = read(args['filename'])
        pubkey = read(args['pubkey_filename'])
        signature = read(args['signature_filename'])
        if check(msg, pubkey, signature):
            if not args['quiet']:
                print('Valid signature')
        else:
            if not args['quiet']:
                print('Invalid signature')
            exit(1)


if __name__ == '__main__':
    main()
