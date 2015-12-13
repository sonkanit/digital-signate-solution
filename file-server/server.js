var express = require('express');
var app = express();
var passport = require('passport');
var LocalStrategy = require('passport-local').Strategy;
var session = require('express-session');
var bodyParser = require('body-parser');
var User = require('./user');

const PORT = 8080;

passport.serializeUser(function(user, done) {
  done(null, user.username);
});

passport.deserializeUser(function(id, done) {
  User.findOne({ username: id }, function(err, user) {
    done(err, user);
  });
});

passport.use(new LocalStrategy(function(username, password, done) {
    
  User.findOne({ username: username }, function(err, user) {
    if (err) {
      return done(err);
    }
      
    if (!user) {
      return done(null, false, { message: 'Incorrect username.' });
    }
      
    if (!user.validPassword(password)) {
      return done(null, false, { message: 'Incorrect password.' });
      }
      
      return done(null, user);
    });
  }
));

app.use('/medias', express.static('medias'));
app.use('/web', express.static('web'));
app.use(bodyParser());
app.use(session({ secret: 'keyboard cat' }));
app.use(passport.initialize());
app.use(passport.session());

app.get('/', function (req, res) {
  res.send('Digital Signate Index Page');
});

app.post('/web/login',
  passport.authenticate('local', { successRedirect: '/web',
                                   failureRedirect: '/web/#/login',
                                   failureFlash: false })
);

app.post('/web/isLoggedIn', function(req, res) {
  if (req.isAuthenticated()) {
    res.send(200, 'yes');
  }
  else {
    res.send(401, 'no');
  }
});

app.post('/web/logout', function(req, res){
    req.logout();
    res.redirect('/');
});
  
app.get('/schedule/:deviceId', function (req, res) {
  res.setHeader('Content-Type', 'text/plain; charset=utf-8')
  var schedule = [{
    dayOfWeek: 0,
    time: '23:59:00',
    resourceId: '/jellyfish.mkv',
    type: 'video'
  }, {
    dayOfWeek: 0,
    time: '23:59:30',
    resourceId: '/tiger.jpg',
    type: 'image'
  }];

  res.end(JSON.stringify(schedule));
});

var server = app.listen(PORT, function () {
  var host = server.address().address;
  var port = server.address().port;

  console.log('server listening at http://%s:%s', host, port);
});
