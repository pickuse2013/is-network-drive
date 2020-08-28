# is-network-drive
test path or disk is it network device

## Install

**node.js**

```bash
npm install is-network-drive
```

## Feature
using N-API call system library
support Apple Mac & Windows

## Usage examples
```
var isNetworkDrive = require("is-network-drive")
```
it will return boolean, if path or drive is network device it will return TRUE, otherwise it will be FALSE.
### Mac
```
isNetworkDrive("/Volumes/Library/SMB-Test")
isNetworkDrive("/Users/pickuse/Project/test")
```

### Windows
```
isNetworkDrive("C:/")
isNetworkDrive("\\192.168.0.1\test")
```