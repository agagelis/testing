var net = require('net');
var textChunk = '';
var server = net.createServer(function(socket) {
	socket.write('Echo server\r\n');
	socket.on('data', function(data){
		console.log(data);
		textChunk = data.toString('utf8');
		console.log(textChunk);
		socket.write(textChunk);
	});
});
server.listen(52275, '192.168.0.81');