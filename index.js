/**
 * author Özgür Çimen on 23.10.2015.
 */
var addon = require('bindings')('deposity');
module.exports = {
    pSrc : function (path) {
        var result = [];
        
        var l = addon.getLenght();
        for(var i = 0 ; i < l ; i++ )
            result.push(path + addon.getSource(i));      
        
        return result;
    }
}

