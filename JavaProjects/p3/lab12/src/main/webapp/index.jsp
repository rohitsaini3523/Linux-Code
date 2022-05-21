<%@ page language="java" contentType="text/html; charset=UTF-8"
pageEncoding="UTF-8"%>
<!DOCTYPE html>
<html>
  <head>
    <meta charset="UTF-8" />
    <title>-EMPLOYEE LOGIN-</title>
  </head>
  <body>
    <h1>-EMPLOYEE LOGIN-</h1>
    <p>${error }</p>
    <form action="http://localhost:9009/JavaMiniProject/emplogin" method="post">
      <label for="username">Username:</label>
      <input type="text" id="username" name="username" /><br />

      <label for="password">Password:</label>
      <input type="password" id="password" name="password" /><br />

      <input type="reset" value="Clear" name="clear" />
      <input type="submit" value="Submit" name="submit" />
    </form>
  </body>
</html>
