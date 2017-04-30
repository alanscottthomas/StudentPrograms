<html>

	<head>

	<title>Room and Key Have Been Added</title>

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
                $key_room = trim($_POST['key_room']);

	 

	    }

	 


	   
	    if(empty($data_missing)){



$key=$key_room;
$room_id=$level_name;

//echo $north;
//echo $room_id;







	        require_once('../../mysqli_connect_lab6_db1.php');

	        

	       $query = "insert into contents_tbl (room_id,chest) VALUES (?,'1')";
               $query2 = "insert into contents_tbl (room_id,key_,key_to_room) VALUES (?,'1',?)";  //key,room_id
	         

	        $stmt = mysqli_prepare($dbc, $query);
                $stmt2 = mysqli_prepare($dbc, $query2);

	         

	        //i Integers

	        //d Doubles

	        //b Blobs

	        //s Everything Else

	         

	        mysqli_stmt_bind_param($stmt,'i',$room_id);
                mysqli_stmt_bind_param($stmt2,'ii',$key,$room_id);
	         

	        mysqli_stmt_execute($stmt);
                mysqli_stmt_execute($stmt2);
	         

	        $affected_rows = mysqli_stmt_affected_rows($stmt);

	         

	        if($affected_rows >= 0){

	             

	            echo 'Room Locked';

	             

	            mysqli_stmt_close($stmt);
                    mysqli_stmt_close($stmt2);

	             

	            mysqli_close($dbc);

	             

	        } else {


	            echo 'Error Occurred<br />';

	            echo mysqli_error();

	             

	            mysqli_stmt_close($stmt);
                    mysqli_stmt_close($stmt2);

	             

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
