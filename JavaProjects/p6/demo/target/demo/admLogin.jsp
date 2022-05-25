<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
<head>
	<meta charset="UTF-8">
	<meta name="viewport" content="width=device-width, initial-scale=1.0">
	<script src="https://cdn.tailwindcss.com"></script>
	<title>-ADMIN LOGIN-</title>
</head>
<body class="bg-gray-400">
<div class="bg-gray-400">
  <h2 class="text-4xl font-semibold border-b pb-2 mx-6">Admin Login</h2>
  <p class="bg-red-300 text-red-900 font-semibold text-xl w-80 rounded-lg my-2 mx-auto"></p>
  <span>${error}</span>
  <div class="bg-gray-600 mx-auto text-center w-1/2 py-5 shadow-xl rounded-3x1 my-96 max-w-2xl">
    <form action="http://localhost:8080/demo/adminlogin" method="post">
      <div class="grid grid-cols gap-4 my-5 mx-8">
        <label for="username" class="text-xl flex items-center">Username:</label>
        <input class="w-full p-1 border-2 placeholder-blue-800 bg-blue-200 border-blue-700 appearance-none rounded-lg focus:outline-none focus:ring-2" type="text" id="username" name="username"><br>
         
        <label for="password" class="text-xl flex items-center">Password:</label>
        <input class="w-full p-1 border-2 placeholder-blue-800 bg-blue-200 border-blue-700 appearance-none rounded-lg focus:outline-none focus:ring-2" type="password" id="password" name="password"><br>
      </div>
      <input class="bg-blue-300 text-xl font-semibold px-4 py-1 rounded-lg hover:bg-blue-800 hover:text-white" type="reset" value="Clear" name="clear" />
      <input class="bg-blue-300 text-xl font-semibold px-4 py-1 rounded-lg hover:bg-blue-800 hover:text-white" type="submit" value="Submit" name="submit" />
  	</form>
  </div>
</div>

</body>
</html>