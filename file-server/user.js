var mongoClient = require('mongodb').MongoClient;
var dbUrl = 'mongodb://localhost:27017/test';

var userDb = null;
mongoClient.connect(dbUrl, function(err, db) {
  if (err == null) {
    console.log("Connected correctly to server.");
    userDb = db.collection('users');
  } else {
    console.log("Unable to connect to server.");
  }
});


exports.findOne = function (query, cb) {
  
  var cursor = userDb.find(query);
  cursor.each(function(err, doc) {
    if (doc != null) {
      var user = new User(doc);
      cb(null, user);
    }
  });  
};

var User = function (doc) {
  this.doc_ = doc;
  this.username = doc.username;
};

User.prototype.validPassword = function (password) {
  //TODO: hash?
  return this.doc_.password === password;
};
