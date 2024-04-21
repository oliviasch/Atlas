const map = L.map('map').setView([51.505, -0.09], 3); // initializes map
// adds tile layer
L.tileLayer('https://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png', {
    attribution: 'Anais'
}).addTo(map);
// define your points of interest (POIs) with coordinates and information
const pois = [
    // put countries here
    {coords: [51.51, -0.11], info: 'temp'} // britain
];
// add markers for each POI and bind popups
pois.forEach(poi => {
    const marker = L.marker(poi.coords).addTo(map);
    marker.bindPopup(poi.info);
    marker.on('click', function () {
        this.openPopup();
    });
});
// handle user interactions with the control box
document.getElementById('toggleMarkers').addEventListener('click', function() {
    // code to toggle markers visibility
});
document.getElementById('changeMapStyle').addEventListener('click', function() {
    // code to change map style
});