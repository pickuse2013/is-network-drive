var addon = require('bindings')('addon.node')
var opsys = process.platform;

module.exports = (folderPath) => {
    // check is system is mac osx
    if (opsys == "darwin") {
        return addon.pathType(folderPath) == "smbfs";
    }

    // check is system is windows
    if (opsys == "win32" || opsys == "win64") {

        // windows api only take like c:\
        if (RegExp('^([a-z]):').test(folderPath)) {

            // take c:\ only
            folderPath = folderPath.slice(0, 2)
        }
        
        // on windows they are only \\192.168.0.1 or Z:\ (mount) is network drive
        // test url is start with \\??????
        if(RegExp('^\\\\\S+$').test(folderPath))
        {
            return true;
        }

        return addon.pathType(folderPath) == "network-drive";
    }

    // check is system is linux
    if (opsys == "linux") {
        throw Error('not support linux yet')
    }

    return false;
}