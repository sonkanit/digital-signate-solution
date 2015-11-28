console.log('hello');
var http = require('http');
const PORT=8080;

function handleRequest(request, response){
    var schedule = [{
            dayOfWeek: 0,
            time: '23:59:00',
            resource: '/media/test.mkv',
            type: 'video'
        }, {
            dayOfWeek: 0,
            time: '23:59:30',
            resource: '/media/test.jpg',
            type: 'image'
        }
    ];

    response.end(JSON.stringify(schedule));
}

var server = http.createServer(handleRequest);

server.listen(PORT, function(){
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
