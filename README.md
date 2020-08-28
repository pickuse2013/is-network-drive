
# is-network-drive
test path or disk is it network device

[![Maintenance](https://img.shields.io/badge/Maintained%3F-yes-green.svg)](https://github.com/pickuse2013/is-network-drive) [![sss](https://badgen.net/npm/v/is-network-drive)](https://www.npmjs.com/package/is-network-drive) ![sss](https://badgen.net/npm/license/is-network-drive)

## Install

**node.js**

```bash
npm install is-network-drive
```

## Feature
- using NAPI call system library
- support Apple Mac & Windows

## Usage examples
```
var isNetworkDrive = require("is-network-drive")
```
it will return boolean, if path or drive is network device it will return TRUE, otherwise it will be FALSE.

### Mac
```
isNetworkDrive("/Volumes/Library/SMB-Test")
isNetworkDrive("/Users/pickuse/Project/test")
isNetworkDrive("/Users/pickuse/Project/tttt")
isNetworkDrive("/Volumes/Library/SMB-Test")
isNetworkDrive("smb://192.168.0.124")
```

### Windows
```
isNetworkDrive("C:\\Users\\Edward\\Desktop")
isNetworkDrive("C:\\")
isNetworkDrive("C://")
isNetworkDrive("Z:\\SMB-Test")
isNetworkDrive("Z://SMB-Test")
isNetworkDrive('\\\\192.168.0.1\\test')
```