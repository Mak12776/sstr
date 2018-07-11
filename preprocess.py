#!/usr/bin/python3

import sys
import os
import json
import re

_files = ('sstr.h', 'sstr.c')
_src_path = 'src'
_outsrc_path = 'outsrc'

class _Config(dict):
    def __missing__(self, key):
        if key in ('file_name', 'struct_pointer'):
            return 'sstr'
        if key == 'struct_name':
            return '_sstr'
        if key == 'function_prefix':
            return 'sstr_'
        if key == 'macro_prefix':
            return 'SSTR_'
        raise KeyError(key)

def _new_alternative(new):
    def alt(old):
        return old.group(0).replace('sstr', new)
    return alt

def _log(t, msg):
    _marks = {'e': '!', 'i': '-'}
    try:
        print('[{}] {}'.format(_marks[t], msg))
    except KeyError:
        raise ValueError('invalid argument passed for t: {}'.format(t))

def main():
    if len(sys.argv) != 2:
        print('usage: {} [config]'.format(sys.argv[0]))
        sys.exit(0)
    try:
        with open(sys.argv[1]) as infile:
            config = _Config(json.load(infile))
    except json.decoder.JSONDecodeError as e:
        _log('e',
            '[!] error: while reading config file \'{}\': {}'.format(
                sys.argv[1], e))
    if not os.path.isdir(_outsrc_path):
        os.mkdir(_outsrc_path)
    for name in _files:
        _log('i', )
        outname = name.replace('sstr', config['file_name'])
        with open(os.path.join(_src_path, name)) as infile:
            with open(os.path.join(_outsrc_path, outname), 'w') as outfile:
                for line in infile:
                    if line.startswith('#include'):
                        line = line.replace(
                            'sstr.h', config['file_name'] + '.h')
                    else:
                        line = line.replace('SSTR_', config['macro_prefix'])
                        line = line.replace('sstr_', config['function_prefix'])
                        line = line.replace('_sstr', config['struct_name'])
                        line = re.sub(
                            '[^a-zA-Z_]?sstr[^a-zA-Z_]?',
                            _new_alternative(config['struct_pointer']),
                            line, re.M)
                    outfile.write(line)
    outtest =  'test_{}.c'.format(config['file_name'])
    with open('test.c') as infile:
        with open(os.path.join(_outsrc_path, outtest), 'w') as outfile:
            for line in infile:
                outfile.write(
                    line.replace('src/sstr.h', config['file_name'] + '.h', 1))
    command = 'gcc -D_GNU_SOURCE {} -o bin/test'.format(
        ' '.join(
            os.path.join(_outsrc_path, name) for name in (
                list(map(
                    lambda s: s.replace('sstr', config['file_name'])
                    , _files
                )) + [outtest]
            )
        )
    )
    os.system(command)

if __name__ == '__main__':
    main()
