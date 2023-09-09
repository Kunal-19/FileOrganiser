let helpObj = require("./help.js");
let organiseObj = require("./organise.js");
let treeObj = require("./tree.js");

//Take input
let input = process.argv.splice(2);
let cmd = input[0];
// console.log(input);
switch(cmd){
    case "help" :
        helpObj.helpKey();
        break;
    case "organise":
        organiseObj.organise(input[1]);
        break;
    case "tree" :
        treeObj.generateTree(input[1],"");
        break;
    default :
        helpObj.wrongPath();
}



// node main.js organise "/Users/medo/Downloads"
//  node main.js tree  "/Users/medo/Downloads"