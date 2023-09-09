let fs = require('fs');
let path = require('path')
let chalk = require('chalk')

function tree(dirPath,indent){
    console.log(indent + chalk.green(path.basename(dirPath)));
    let children = fs.readdirSync(dirPath);

    for(let i=0; i<children.length; i++){
        let child_path = path.join(dirPath,children[i]);
        let isFile = fs.lstatSync(child_path).isFile();

        if(isFile == false){
            tree(child_path,"-" + indent);
        }else console.log(chalk.yellowBright(indent + "->" + children[i]));
    }
}

module.exports = {
    "generateTree" : tree
}