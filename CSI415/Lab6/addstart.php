<html>

	<head>

	<title>Establish Starting Room</title>

	</head>

	<body>
<body style="font-family:Arial;background-color:#F0ECDC;color: #461e72">

	<?php
//echo '<body style=background-color:#F0ECDC>';
	 

	if(isset($_POST['submit'])){

	     

	    $data_missing = array();

	     

	    if(empty($_POST['level_name'])){

	 

	        // Adds name to array

	        $data_missing[] = 'level_name';

	 

	    } else {

	 

	        // Trim white space from the name and store the name
	        $level_name = trim($_POST['level_name']);

	 

	    }

	 

	  

	   
	    if(empty($data_missing)){

	         

	        require_once('../../mysqli_connect_lab6_db1.php');

	         

	       $query = "INSERT INTO contents_tbl (room_id,start) VALUES (?,'1')";

	         

	        $stmt = mysqli_prepare($dbc, $query);

	         

	        //i Integers

	        //d Doubles

	        //b Blobs

	        //s Everything Else

	         

	        mysqli_stmt_bind_param($stmt,"s",$level_name);

	         

	        mysqli_stmt_execute($stmt);

	         

	        $affected_rows = mysqli_stmt_affected_rows($stmt);

	         

	        if($affected_rows == 1){

	             

	            echo 'Start Room Selected';

	             

	            mysqli_stmt_close($stmt);

	             

	            mysqli_close($dbc);

	             

	        } else {

	             

	            echo 'Error Occurred<br />';

	            echo mysqli_error();

	             

	            mysqli_stmt_close($stmt);

	             

	            mysqli_close($dbc);

	             

	        }

	         

	    } else {

	         

	        echo 'You need to enter the following data<br />';

	         

	        foreach($data_missing as $missing){

	             

	            echo "$missing<br />";

	             

	        }

	         

	    }

	     
}
	

	 

	?>

	 

	

	</body>

	</html>
