#!/usr/bin/env node

let helpObj = require("./help.js");
let organiseObj = require("./organise.js");
let treeObj = require("./tree.js");

//Take input
let input = process.argv.splice(2);
let cmd = input[0];
let dir = input[1];

if(dir == undefined){
    dir = process.cwd();
}else dir = input[1];

switch(cmd){
    
    case "help" :
        helpObj.helpKey();
        break;
    case "organise":
        organiseObj.organise(dir);
        break;
    case "tree" :
        treeObj.generateTree(dir,"");
        break;
    default :
        helpObj.wrongPath();
}



// node main.js organise "/Users/medo/Downloads"
//  node main.js tree  "/Users/medo/Downloads"