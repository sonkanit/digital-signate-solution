console.log('hello');
var http = require('http');
var static = require('node-static');
var Router = require('router');
var finalhandler = require('finalhandler')
var fileServer = new static.Server('./medias');

const PORT=8080;

var router = Router()

router.get('/schedule/**', function (request, response) {
    response.setHeader('Content-Type', 'text/plain; charset=utf-8')
    var schedule = [{
            dayOfWeek: 0,
            time: '23:59:00',
            resource: '/jellyfish.mkv',
            type: 'video'
        }, {
            dayOfWeek: 0,
            time: '23:59:30',
            resource: '/medias/test.jpg',
            type: 'image'
        }
    ];

    response.end(JSON.stringify(schedule));
});

router.get('/**', function (request, response) {
    request.addListener('end', function () {
        fileServer.serve(request, response);
    }).resume();
});

function handleRequest(request, response){
    router(request, response, finalhandler(request, response));
};

var server = http.createServer(handleRequest);

server.listen(PORT, function(){
    //Callback triggered when server is successfully listening. Hurray!
    console.log("Server listening on: http://localhost:%s", PORT);
});
