const map = L.map('map').setView([51.505, -0.09], 3); // Initializes map
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
                    fillColor: 'red', // TO-DO: change gradient based on the amount of co2
                    fillOpacity: 0.5,
                    color: 'red', // TO-DO: change gradient based on the amount of co2
                    colorOpacity: 0.5
                });
            });
        });
});
