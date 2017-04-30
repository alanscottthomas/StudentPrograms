<html>

	<head>

	<title>West room connected</title>

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
                $west_room = trim($_POST['west_room']);

	 

	    }

	 


	   
	    if(empty($data_missing)){



$west=$west_room;
$room_id=$level_name;

//echo $north;
//echo $room_id;







	        require_once('../../mysqli_connect_lab6_db1.php');

	        

	       $query = "UPDATE rooms_tbl SET west = ? WHERE room_id= ?";

	         

	        $stmt = mysqli_prepare($dbc, $query);

	         

	        //i Integers

	        //d Doubles

	        //b Blobs

	        //s Everything Else

	         

	        mysqli_stmt_bind_param($stmt,'si',$west,$room_id);

	         

	        mysqli_stmt_execute($stmt);

	         

	        $affected_rows = mysqli_stmt_affected_rows($stmt);

	         

	        if($affected_rows >= 0){

	             

	            echo 'West Room Connected';

	             

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
