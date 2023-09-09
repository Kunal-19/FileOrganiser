let fs = require("fs");
let path = require("path");
let helpObj = require("./help.js");
let extObj = require("./ext.js");


let extensions = {
    "media" : ['mp4','mkv'],
    "Pictures" : ['jpg','jpeg','png'],
    "Documents" : ['zip','pdf','doc','pages','xlxs','csv','txt'],
    "Programs" : ['ipynb','cpp','c','py','java','js','cph']
}


function copyFiles(srcPath,dest_path,type){
    let folder = path.join(dest_path,type);

    if(fs.existsSync(folder) == false){
        fs.mkdirSync(folder);
    }
    let fileName = path.basename(srcPath);
    let destFilePath = path.join(folder,fileName);
    fs.copyFileSync(srcPath,destFilePath);
    fs.unlinkSync(srcPath);
}

function organiseFiles(dirPath,dest_path){
    let details = fs.readdirSync(dirPath);

    for(let i = 0; i<details.length; i++){
        let child_addr = path.join(dirPath,details[i]);
        let isFile = fs.statSync(child_addr).isFile();

        if(isFile == true){
            let child_ext = path.extname(child_addr);
            child_ext = child_ext.slice(1);

            for(let type in extensions){
                let ctype = extensions[type];
                for(let i=0; i<ctype.length; i++){

                    if(ctype[i] == child_ext){
                        copyFiles(child_addr,dest_path,type);
                    }
                }
            }
        }
    }
}

function organise(dirPath){
    if(dirPath == undefined){
        helpObj.wrongPath();
        return ;
    }else{
        let exist = fs.existsSync(dirPath);
        if(exist == false){
            helpObj.wrongPath();
            return;
        } 
    }
    let dest_path = path.join(dirPath,"organised_files");
    if(fs.existsSync(dest_path) == false){
        fs.mkdirSync(dest_path);
    }
    organiseFiles(dirPath,dest_path);
}

module.exports = {
    "organise" : organise
}