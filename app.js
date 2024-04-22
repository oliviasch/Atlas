const map = L.map('map').setView([51.505, -0.09], 3); // initializes map
// adds tile layer
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: 'Anais'
}).addTo(map);
// compiles GeoJSON file URLs
const geojsonFiles = [
    'country/1.geojson',
    'country/2.geojson',
    'country/3.geojson',
];
// store GeoJSON layers
const countryLayers = {};
// loop through each GeoJSON file and add it
geojsonFiles.forEach(geojsonUrl => {
    fetch(geojsonUrl)
        .then(response => response.json())
        .then(data => {
            function customStyle(feature) {
                return {
                    fillColor: 'white', // fill color
                    fillOpacity: 0.01, // fill opacity to 0 for complete transparency
                    color: 'white', // border color
                    colorOpacity: 0.01, // border color opacity to 0 for complete transparency
                    weight: 2 // border weight
                };
            }
            const countryLayer = L.geoJSON(data, {
                style: customStyle
            }).addTo(map);
            // store the layer
            countryLayers[geojsonUrl] = countryLayer;
            // click event listener for the layer
            countryLayer.on('click', function (event) {
                // resets all other country layers
                Object.values(countryLayers).forEach(layer => {
                    layer.setStyle(customStyle);
                });
                // changes layer color
                event.layer.setStyle({
                    fillColor: 'green',
                    fillOpacity: 0.5,
                    color: 'green',
                    colorOpacity: 0.5
                });
            });
        });
});
function sendData() {
    const selectedData = Array.from(document.getElementById('searchData').selectedOptions).map(option => option.value);
    const year = document.getElementById('searchYear').value.trim();
    // checks what user has entered
    if (selectedData.length > 0 && year !== '') {
        const dataToSend = { data: selectedData, year: year };
        ws.send(JSON.stringify(dataToSend)); // Send the data as JSON string
    } else {
        alert('Please select data and enter a year');
    }
}
function invokeCppProgram(selectedData, year) {
    // executes a C++ executable with the selected data and year
    const { exec } = require('child_process');
    exec('path/to/your/cpp/executable ' + selectedData.join(',') + ' ' + year, (error, stdout, stderr) => {
        if (error) {
            console.error(`Error executing C++ program: ${error.message}`);
            // error response to the client if needed
        }
        if (stderr) {
            console.error(`C++ program STDERR: ${stderr}`);
            // error response to the client if needed
        }
        console.log(`C++ program output: ${stdout}`);
        // send the output back to the WebSocket client if needed
    });
}
