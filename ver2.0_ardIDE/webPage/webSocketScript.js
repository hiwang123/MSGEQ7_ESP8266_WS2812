
function presets(value) {
	sendManual(parseInt(value));
}
		

function sendManual(type){
	var ipValue = document.getElementById('ip').value;
	$.get(ipValue, {'data': type});		
}			


