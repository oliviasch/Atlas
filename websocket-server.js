// websocket-server.js
const WebSocket = require('ws');
const wss = new WebSocket.Server({ port: 8080 });
wss.on('connection', function connection(ws) {
    console.log('Client connected');

    ws.on('message', function incoming(message) {
        console.log('Received: %s', message);
    });

    ws.send('Hello from WebSocket server!');
});
function executeCppFunction(data, callback) {
    // code to execute function in C++
    // TO DO- replace this with your actual method of invoking C++ code
    console.log('Executing function with data:', data);
    const { exec } = require('child_process');
    exec('C:\\Users\\olivi\\Desktop\\2024 spring\\1. COP3530\\projects\\atlas\\cmake-build-debug' + data, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing C++ function: ${error.message}`);
            callback('Error executing C++ function');
            return;
        }
        if (stderr) {
            console.error(`C++ function STDERR: ${stderr}`);
            callback('C++ function encountered an error');
            return;
        }
        console.log(`C++ function output: ${stdout}`);
        callback(stdout.trim()); // sends the output back to the WebSocket client
    });
}
console.log('WebSocket server running on ws://localhost:8080');
