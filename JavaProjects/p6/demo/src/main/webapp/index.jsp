<%@ page language="java" contentType="text/html; charset=UTF-8"
    pageEncoding="UTF-8"%>
<!DOCTYPE html>
<div class="bg-gray-400">

<h2 class="text-4xl font-semibold border-b pb-2 mx-6">Home Page</h2>
<html>
  
  <head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <script src="https://cdn.tailwindcss.com"></script>
    <title>-LOGIN-</title>
  </head>
  <body class="bg-gray-400">
    
    <div class="bg-gray-600 mx-auto text-center w-1/2 py-5 shadow-x1 rounded-3x1 my-96 max-w-2xl">
      <h1 class="font-bold text-2xl">-LOGIN-</h1>
      <form name="myForm" action="http://localhost:8080/demo/adminlogin" method="get">
        <div class="my-5 mx-8 grid grid-cols-1 gap-4">
          <input class="bg-blue-300 text-x1 font-semibold px-4 py-1 hover:bg-blue-800 hover:text-white w-full appearance-none rounded-lg border-2 border-blue-700 p-1 placeholder-blue-800 focus:outline-none focus:ring-2" type="submit" value="Admin" name="submit" />
        </div>
      </form>

      <form name="myForm" action="http://localhost:8080/demo/emplogin" method="get">
        <div class="my-5 mx-8 grid grid-cols-1 gap-4">
          <input class="bg-blue-300 text-x1 font-semibold px-4 py-1 hover:bg-blue-800 hover:text-white w-full appearance-none rounded-lg border-2 border-blue-700 p-1 placeholder-blue-800 focus:outline-none focus:ring-2" type="submit" value="Employee" name="submit" />
        </div>
      </form>
    </div>
  </body>
</html>
</div>