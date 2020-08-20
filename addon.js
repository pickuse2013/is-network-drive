
var addon = require('bindings')('addon.node')
var opsys = process.platform;

exports.detectFolderType = (folderPath) => {
    if (opsys == "darwin") {
        return addon.pathType(folderPath)
    } else if (opsys == "win32" || opsys == "win64") {
        return addon.pathType(folderPath)
    } else if (opsys == "linux") {
        throw Error('not support linux')
    }
}
