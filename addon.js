
var addon = require('bindings')('addon.node')
var opsys = process.platform;


exports = (folderPath) => {
    if (opsys == "darwin") {
        return addon.pathType(folderPath)
    } else if (opsys == "win32" || opsys == "win64") {
        // TODO: 清除路徑尾巴
        return addon.pathType(folderPath)
    } else if (opsys == "linux") {
        throw Error('not support linux')
    }
}


console.log(addon.pathType("\\\\192.168.0.124"))



// var isNetworkDrive = require("is-network-drive")("C://")