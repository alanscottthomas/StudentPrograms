<!DOCTYPE>
<HTML>
<HEAD>
<style>
.move a {
	color: #FBB03B; text-shadow: 0 0 0px rgba(255,0,0,100); letter-spacing:1px; text-align:center; 
}
</style>
<BODY>
	<body style="background-color:black;">
		<font color="white">
<div class = "move">
<a href = "home_page.php">   map maker home</a>
</div>
<?php
	//variables to store the database connection info//
	$host="localhost";
	$u="root_se";
	$p="Griffen644/";
	$db="game";
	//---------------//
	
	//create connection to SQL//
	$conn = new mysqli($host, $u, $p, $db);
	
	//if statement if connection fails
	if(! $conn){
		printf("Connection failed: %s\n",$conn->connect_error);
		exit();
	}
	
	//if connection est. insert the info into the DB
	$sql = "insert into `stage_tbl`(`stage_id`) values (null);";
	if(mysqli_query($conn, $sql)){
		echo"<br><br>stage created";        //display message to let user know stage made

	}
	//if stage cannot be created display an error
	else{
		echo"error";
	}
	
	//send user back to stages page
	header("stages.php");
	$conn->close();                       //close the connection
?>
</font>
</BODY>
</HTML>