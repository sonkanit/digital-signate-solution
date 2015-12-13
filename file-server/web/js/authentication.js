app.factory('Authentication', ['$http', function ($http) {

  var isLoggedIn = false;
  $http.post('/web/isLoggedIn').then(function () {
    isLoggedIn = true; 
  }, function () {
    isLoggedIn = false;
  });
  
  var Authentication = function () {
  };
  
  Authentication.isLoggedIn = function () {
    return isLoggedIn;
  };
  
  Authentication.logout = function () {
    $http.post('/web/logout').then(function () {
      isLoggedIn = false;
    });
  };
  
  return Authentication; 
}]);
