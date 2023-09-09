function cmd(){
    console.log(`List of all the commands: 
    1. node main.js organise "dir_path"
    2. node main.js tree "dir_path"
    3. node main.js help`)
}

function wrongPath(){
    console.log(`Please enter a valid command. Type 
        node main.js help
        to get the list of commands`);
}

module.exports = {
    "helpKey" : cmd,
    "wrongPath" : wrongPath
}