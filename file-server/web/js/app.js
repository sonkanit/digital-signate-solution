var app = angular.module('app', [
  'ngRoute',
  'appControllers',
  'ui.bootstrap'
]);

var appControllers = angular.module('appControllers', []);

appControllers.controller('MainCtrl', ['$scope', 'Authentication',
  function ($scope, Authentication) {
    $scope.isLoggedIn = Authentication.isLoggedIn;
    $scope.logout = Authentication.logout;
    
    $scope.$on('logout', function () {
      $scope.isLoggedIn = false;
    });
}]);

app.config(['$routeProvider',
	function($routeProvider) {
		$routeProvider.
		when('/login', {
      templateUrl: 'templates/login.html',
      controller: 'LoginCtrl'
    }).
    otherwise({
      redirectTo: '/'
    });
}]);
