var addon = require('bindings')('deposity');

console.log(addon.getSource(1));
console.log(addon.getLenght());

module.exports = {
    pSrc : function (path) {
        var result = [];
        
        var l = addon.getLenght();
        for(var i = 0 ; i < l ; i++ )
            result.push(path + addon.getSource(i));      
        
        return result;
    }
}

