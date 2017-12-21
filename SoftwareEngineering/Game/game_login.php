<!DOCTYPE html>
<html >
<?php
session_start();
?>


<head>
  <meta charset="UTF-8">
  <title>Game Login</title>
  
  <link rel="stylesheet" href="https://cdnjs.cloudflare.com/ajax/libs/normalize/5.0.0/normalize.min.css">

  
      <style>
      @import url(http://fonts.googleapis.com/css?family=Open+Sans);
.btn { display: inline-block; *display: inline; *zoom: 1; padding: 4px 10px 4px; margin-bottom: 0; font-size: 13px; line-height: 18px; color: #333333; text-align: center;text-shadow: 0 1px 1px rgba(255, 255, 255, 0.75); vertical-align: middle; background-color: #f5f5f5; background-image: -moz-linear-gradient(top, #ffffff, #e6e6e6); background-image: -ms-linear-gradient(top, #ffffff, #FBB03B); background-image: -webkit-gradient(linear, 0 0, 0 100%, from(#ffffff), to(#e6e6e6)); background-image: -webkit-linear-gradient(top, #ffffff, #e6e6e6); background-image: -o-linear-gradient(top, #ffffff, #e6e6e6); background-image: linear-gradient(top, #ffffff, #e6e6e6); background-repeat: repeat-x; filter: progid:dximagetransform.microsoft.gradient(startColorstr=#ffffff, endColorstr=#e6e6e6, GradientType=0); border-color: #e6e6e6 #e6e6e6 #e6e6e6; border-color: rgba(0, 0, 0, 0.1) rgba(0, 0, 0, 0.1) rgba(0, 0, 0, 0.25); border: 1px solid #e6e6e6; -webkit-border-radius: 4px; -moz-border-radius: 4px; border-radius: 4px; -webkit-box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.2), 0 1px 2px rgba(0, 0, 0, 0.05); -moz-box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.2), 0 1px 2px rgba(0, 0, 0, 0.05); box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.2), 0 1px 2px rgba(0, 0, 0, 0.05); cursor: pointer; *margin-left: .3em; }
.btn:hover, .btn:active, .btn.active, .btn.disabled, .btn[disabled] { background-color: #e6e6e6; }
.btn-large { padding: 9px 14px; font-size: 15px; line-height: normal; -webkit-border-radius: 5px; -moz-border-radius: 5px; border-radius: 5px; }
.btn:hover { color: #333333; text-decoration: none; background-color: #e6e6e6; background-position: 0 -15px; -webkit-transition: background-position 0.1s linear; -moz-transition: background-position 0.1s linear; -ms-transition: background-position 0.1s linear; -o-transition: background-position 0.1s linear; transition: background-position 0.1s linear; }
.btn-primary, .btn-primary:hover { text-shadow: 0 -1px 0 rgba(0, 0, 0, 0.25); color: #ffffff; }
.btn-primary.active { color: rgba(0, 0, 255, 0.75); }
.btn-primary { background-color: #4a77d4; background-image: -moz-linear-gradient(top, #FBB03B, #FBB03B); background-image: -ms-linear-gradient(top, #FBB03B, #FBB03B); background-image: -webkit-gradient(linear, 0 0, 0 100%, from(#FBB03B), to(#FBB03B)); background-image: -webkit-linear-gradient(top, #FBB03B, #FBB03B); background-image: -o-linear-gradient(top, #6eb6de, #4a77d4); background-image: linear-gradient(top, #6eb6de, #4a77d4); background-repeat: repeat-x; filter: progid:dximagetransform.microsoft.gradient(startColorstr=#6eb6de, endColorstr=#4a77d4, GradientType=0);  border: 1px solid #FBB03B; text-shadow: 1px 1px 1px rgba(100,0,0,0.4); box-shadow: inset 0 1px 0 rgba(255, 255, 255, 0.2), 0 1px 2px rgba(0, 0, 0, 0.5); }
.btn-primary:hover, .btn-primary:active, .btn-primary.active, .btn-primary.disabled, .btn-primary[disabled] {
	filter: none;
	background-color: #FBB03B;
}
.btn-block { width: 100%; display:block; }

* { -webkit-box-sizing:border-box; -moz-box-sizing:border-box; -ms-box-sizing:border-box; -o-box-sizing:border-box; box-sizing:border-box; }

html { width: 100%; height:100%; overflow:hidden; }

body {
	width: 100%;
	height: 100%;
	font-family: 'Open Sans', sans-serif;
	background: #099996;
	background: -moz-radial-gradient(0% 100%, ellipse cover, rgba(255,128,138,.4) 10%,rgba(255,114,76,0) 40%),-moz-linear-gradient(top,  rgba(255,173,219,.25) 0%, rgba(255,60,87,.4) 100%), -moz-linear-gradient(-45deg,  #670d10 0%, #092756 100%);
	background: -webkit-radial-gradient(0% 100%, ellipse cover, rgba(255,128,138,.4) 10%,rgba(255,114,76,0) 40%), -webkit-linear-gradient(top,  rgba(255,173,219,.25) 0%,rgba(255,60,87,.4) 100%), -webkit-linear-gradient(-45deg,  #67dd10 0%,#092756 100%);
	background: #000;
	
  
}
.login { 
  position: absolute;
  top: 50%;
  left: 50%;
  margin: -150px 0 0 -150px;
  width:300px;
  height:300px;
}
.login h1 {
	color: #FBB03B;
	text-shadow: 0 0 0px rgba(255,255,255,1.00);
	letter-spacing: 1px;
	text-align: center;
}

.signup {
	
	position: absolute;
	top: 81%;
	left: 50%;
	margin-top: -8px;
	margin-right: 0;
	margin-left: -150px;
	margin-bottom: 0;
	width: 300px;
	height: 300px;
}
.signup h3 { color: #fff; text-shadow: 0 0 0px rgba(0,0,0,0); letter-spacing:1px; text-align:center; }
.signup button{
  position: absolute;
  top: 70%;
  left: 87%;
  margin: -150px 0 0 -150px;
  background-color: #FBB03B;
  border-width: 0px;
  color: white;
  
}

input { 
  width: 100%; 
  margin-bottom: 10px; 
  background: rgba(0,0,0,0.3);
  border: none;
  outline: none;
  padding: 10px;
  font-size: 13px;
  color: #FBB03B;
  text-shadow: 1px 1px 1px rgba(0,0,0,100);
  border: 1px solid rgba(0,0,0,0.3);
  border-radius: 4px;
  box-shadow: inset 0 -5px 45px rgba(100,100,100,0.2), 0 1px 1px rgba(255,255,255,0.2);
  -webkit-transition: box-shadow .5s ease;
  -moz-transition: box-shadow .5s ease;
  -o-transition: box-shadow .5s ease;
  -ms-transition: box-shadow .5s ease;
  transition: box-shadow .5s ease;
}
input:focus { box-shadow: inset 0 -5px 45px rgba(100,100,100,0.4), 0 1px 1px rgba(255,255,255,0.2); }

      </style>

  <script src="https://cdnjs.cloudflare.com/ajax/libs/prefixfree/1.0.7/prefixfree.min.js"></script>

</head>

<body>
  <div class="login">
    <h1>login</h1>
    <form action = "login.php" method="post">
      <input type="text" name="u" placeholder="Username" required="required" autofocus="true" />
        <input type="password" name="p" placeholder="Password" required="required" />
        <button type="submit" class="btn btn-primary btn-block btn-large">login</button>
    </form>
</div>
<br />
<div class="signup">

<form action = "signup.php">
<button>register</button>
</form>
</div>

</body>
</html>
