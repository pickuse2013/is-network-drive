var addon = require('bindings')('addon.node')
var opsys = process.platform;


exports = (folderPath) => {
    if (opsys == "darwin") {
        return addon.pathType(folderPath)
    } else if (opsys == "win32" || opsys == "win64") {
        if (RegExp('^([a-z]):').test(folderPath)) {
            folderPath = folderPath.slice(0, 3)
        }

        return addon.pathType(folderPath)
    } else if (opsys == "linux") {
        throw Error('not support linux')
    }
}