/*

Name: Mesa Spottedcorn, Kevin Magee, Alan Thomas

Class: CSI415

Assignment: Lab6 - NerdCraft

Purpose: This progam allows a user to utilize map information stored in a DB to play a game. Their user information is persistant.

Notes: None
*/



package lab6;

import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.nio.file.Files;
import java.nio.file.Paths;
import java.nio.file.StandardOpenOption;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.Scanner;
import java.util.regex.Pattern;


public class Lab6 {
    static Boolean unlocked=false;                        //variable to determine if our chest has been opened. 
    static int array_count=0;
    //static int[] keys;
    static int[] keys =new int[50];
    static int previous_room=0;
    
//METHOD TO PRINT THE MENU FOR THE USER//
    public static void main(String[] args) throws ClassNotFoundException, SQLException 
    {
        Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        System.out.print("\n\n");
        System.out.print("==========MENU==========\n");
        System.out.print("(A) to start a new game\n(B) continue an old game \n(C) List levels \n(Q) to exit\n");  //printing menu
        System.out.print("\n=========================\n");
        System.out.print("Input: ");

        Pattern valid_ans = Pattern.compile("[aA-zZ]");                                 //input checking
        while (!user_input.hasNext(valid_ans))                                          //input validation for menu selection
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter menu option: ");
            user_input.next();
        }
        char ans = user_input.next(".").charAt(0);                                      //placing the user's input into a char
        //SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {

            //start new game
            case 'a':
            case 'A':
                new_game();
                break;

            //continue old game
            case 'b':
            case 'B':
                old_game();
                break;
                
            //print levels
            case 'c':
            case 'C':
                print_levels();
                break;    
                

            //quit    
            case 'q':
            case 'Q':
                break;
            //default statement
            default:
                System.out.println("\n-Invalid Selection-");
                main(null);                                                             
            //END SWITCH//               
        } 
    }
    

    
    
    
    
    //PRINT LEVELS//   
    public static void print_levels() throws ClassNotFoundException, SQLException 
    {
        System.out.print("\n\n");
        System.out.print("|Level Names|\n");
        System.out.print("______________________________________\n");
        //TRY STATEMENT FOR PULLING INFO FROM DB//
        try 
            {
                Class.forName("com.mysql.jdbc.Driver").newInstance();
                Connection con = DriverManager.getConnection("jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false", "root", "password123");  //DB connection info
                Statement stmt = con.createStatement();
                ResultSet rs = stmt.executeQuery("select level_name from levels_tbl");           //selecting all entries from the student_tbl
                    while (rs.next()) 
                        {
                            System.out.println(rs.getString(1));   //id,last,class,major
                        }
               stmt.close();
                    con.close();                                                            //closing connection
                try 
                    {
                        File f = new File("error_log.txt");                                  //attempting to create the log file to document our access times
                            if (f.exists()) 
                                {
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                            //creating a string with the current date and time
                                    Files.write(Paths.get("error_log.txt"), ("\r\nStudent DB was accessed at: "+"<" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                                } 
                            else 
                                {
                                    PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                                    String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm:ss.SSS").format(new Date());                           //creating a string with the current date and time
                                    myfile.print("Student DB was accessed at: "+"<"+"  <" + timeStamp + ">");     //printing what method had an error
                                    myfile.close();
                                }
            } 
                //CATCH STATEMENT IF FILE CREATIONG FAILED//
                catch (IOException b) 
                    {                                                                          
                        System.out.println("-Unable to generate log file-");                //statement to print an error in the event we couldn't write/create the file       
                    }
                
            } 
        //CATCH STATEMENT IF WE COULDN'T PULL DATA//
        catch (Exception e) 
            {
                System.out.println("-Error detected- Unable to print information-");
            }
       
        //TRY STATEMENT FOR CREATING ERROR FILE//
        try 
            {
                File f = new File("error_log.txt");
                    if (f.exists()) 
                        {
                            String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());        //creating a string with the current date and time
                            Files.write(Paths.get("error_log.txt"), ("\r\nError generated at: RETRIEVING DATA FROM student_tbl(print_users method) <" + timeStamp + ">").getBytes(), StandardOpenOption.APPEND);  //appending to the existing file
                        } 
                    else 
                        {
                            PrintWriter myfile = new PrintWriter("error_log.txt");                                                        //creating a txt file in the directory that the program resides in
                            String timeStamp = new SimpleDateFormat("MM / dd / yyyy HH:mm").format(new Date());                           //creating a string with the current date and time
                            myfile.print("Error generated at: RETRIEVING DATA FROM student__tbl(print_users method)  <" + timeStamp + ">"); //printing method location & timestamp to the file
                            myfile.close();
                        }
            } 
        //CATCH STATEMENT IF WE FAILED TO WRITE TO THE FILE..    
        catch (IOException b) 
                {                                                                          
                    System.out.println("-Unable to generate log file-");       
                }
        //-------------------------------------------//
        System.out.print("______________________________________\n");
        main(null);
    }
//------------------------//
    
    
    
    
    
    
    




    //method to start a new game
    public static void new_game() throws ClassNotFoundException, SQLException
    {
        Boolean name_check=false;
        Boolean level_check=false;
        
        Scanner user_input2 = new Scanner(System.in); 
        System.out.print("Enter your desired level to play: ");          //printing username info
        String level = user_input2.next(); 
       
        
        
        
        
        //calling the name check method to see if this player is in the DB already
        level_check=check_level(level);
        
        //name does not exists
        if(level_check==true)
        {
           // make_player(level);       //sending player name to be inserted into the DB
            System.out.print("\n-Your level has been found!-\n");  //Why have a social life when you have World of NerdCraft?
            //start_game(level);
        }
        
        //name is already in the DB, do not pass go
        else if(level_check==false)
        {
            System.out.print("\n-Level doesn't exist-\n");
            main(null); //return the user to the main menu
        } 
        
        
        
        
        
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter your desired username(alpha only, do not exceed 50 characters): ");          //printing username info
        Pattern valid_name = Pattern.compile("[aA-zZ]*{1,50}");                                              //kleene
        while(!user_input.hasNext(valid_name))                                                               //if input isn't valid ask again
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String name = user_input.next();                                                                    //save user input
        
        //calling the name check method to see if this player is in the DB already
        name_check=check_name(name);
        
        //name does not exists
        if(name_check==false)
        {
            make_player(name);       //sending player name to be inserted into the DB
            System.out.print("\n-Your hero has been created! Welcome to World of NerdCraft!-\n");  //Why have a social life when you have World of NerdCraft?
            start_game(name,level);
        }
        
        //name is already in the DB, do not pass go
        else if(name_check==true)
        {
            System.out.print("\n-Sorry, but the Dungeon Master says this hero is already in the realm-\n");
            main(null); //return the user to the main menu
        }     
    }
    
    
    
    
    //method to continue a game
     public static void old_game() throws ClassNotFoundException, SQLException
    {
        Boolean name_check=false;
        
        Scanner user_input = new Scanner(System.in); 
        System.out.print("Enter your hero's name: ");                                       //get name
        Pattern valid_name = Pattern.compile("[aA-zZ]*{1,50}");                             //kleene
        while(!user_input.hasNext(valid_name))                                              //if invalid input
        {
            System.out.print("-Invalid Input-\n");
            System.out.print("Enter the last name: ");
            user_input.next();  
        }
        String name = user_input.next();                                                   //saving user input
        
        //calling the name check method to see if this player is in the DB already
        name_check=check_name(name);
        
        //name does not exists
        if(name_check==false)
        {
            System.out.print("\n-Your hero cannot be found; the Skeleton King may have devoured them! -\n");  //Why have a social life when you have World of NerdCraft?
            main(null);
        }
        
        //found the player
        else if(name_check==true)
        {
            System.out.print("\n-Your hero has been found, loading your game world now-\n");
            start_game(name,"DEFAULT");  //found the user, call stat game with their data //need to add a get level function
        }      
    }
     
     //loading the location data of the player
     public static void start_game(String name, String level) throws ClassNotFoundException, SQLException
     {
                String sql = "SELECT * FROM player_tbl WHERE name=?";  //creating a string to use for the select statement
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getLong(3)==0)               //means this a new player
                            {
                               find_start(name,rs.getInt(1),level);
                               
                            }
                            else
                            {
                              move(name,rs.getInt(1),rs.getInt(3));     //calling move with the user information
                            }
                        }
    // rs.close();
                 conn.close();                                                       //closing con
     }
     
     
     //method to continue a game
     public static void make_player(String name) throws SQLException, ClassNotFoundException
    {
       String sql = "INSERT INTO player_tbl (name)" + "VALUES (?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                //Statement st = conn.createStatement();
                preparedStatement.executeUpdate();                                                                         //pushing the INSERT command to the DB    
                conn.close();                                                                                              //close con
    }
     
    

//method to move the player to different rooms
     public static void move(String name,Integer player_id, Integer room) throws ClassNotFoundException, SQLException
    {
                update_player_location(name,room);                                                                         //saving player's current location so they can continue later
        
        int last=0;
                String room_string=Integer.toString(room);                                                                //convert int to string
                String sql = "SELECT * FROM contents_tbl WHERE room_id=?";  //creating a string we'll use to select contents
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, room_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                Boolean key=false; 
                Boolean visited;
                visited=check_visited(name,player_id,room);                                                               //set bool according to info we saved into vesited table
                                                                                             
                //checking what is in the current room
                //3-enemy, 4-key_, 5-chest, 6-start, 7-end
                int rowcount=0;
                if(rs.last())
                {
                    rowcount=rs.getRow();
                    rs.beforeFirst();
                }
                System.out.print(rowcount);
                
                while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==1)          //if enemy
                            {
                               if(visited==false)
                               {
                                   enemy_art();
                                   System.out.print("\n-There's a Murloc in this room! After a struggle you are able to fend them off! -\n");   
                               }
                               else
                               {
                                 System.out.print("\n-There's the remains of a Murloc in this room, he's starting to smell funny. -\n");   
                               } 
                                                             
                            }
                            
                            if(rs.getInt(4)==1)         //if key
                            {
                               if(visited==false)
                               {
                                 int key_val=0;
                                   key_art();
                                 System.out.print("\n-There's a key in this room! You quickly stuff it in your bag of holding.-\n");   
                                 
                                 key_val=get_key_data(room);
                                 System.out.print("\nKEYVAL: "+key_val);
                                 keys[array_count]=key_val;
                                 array_count++;
                                 
                                 update_inventory(player_id,room,key_val,4);
                               }
                               else
                               {
                                 System.out.print("\n-Nothing left here, just the dusty outline of an old key.. -\n");   
                               }                               
                            }
                            
                             if(rs.getInt(5)==1)       //if chest
                            {
                               if(visited==false)
                               {
                                 System.out.print("\n-There's a locked door here!-\n");   
                                 //key=check_key(name,player_id);
                                 int i=0;
                                 while (i <= array_count)
                                 {
                                     //if(keys[array_count]==room)
                                     if(keys[i]==room)
                                     {
                                         key=true;
                                     }
                                 i++;
                                 }
                                 
                                 if(key==true)
                                 {
                                   //chest_open_art();
                                     System.out.print("\n-You unlock the door and are now able to continue!-\n");   
                                 unlocked=true;
                                 }
                                 
                                  if(key==false)
                                 {
                                   System.out.print("\n-ArrayVal: "+keys[0]);   
                                     System.out.print("\n-Hmm...better find a key to open this!-\n");  
                                   last=get_last(player_id);
                                   get_directions(name,player_id,last);
                                    //unlocked=false;
                                 }
                                visited=true;         
                               }
                                                            
                           else if(visited==true)
                             {
                                
                                 key=check_key(name,player_id);
                                 System.out.print("\n-No more locked door!-\n");
                                 if(unlocked==false)
                                 {
                                    if(key==true)
                                    {
                                        //chest_open_art();
                                        System.out.print("\n-You unlock the door and can now move forward!-\n");
                                        unlocked=true;
                                        
                                    }
                                    
                                    if(key==false)
                                    {
                                      System.out.print("\n-Hmmm...you still need to find the key-\n"); 
                                      last=get_last(player_id);
                                   get_directions(name,player_id,last);
                                    }
                                 }
                                else if(unlocked==true)
                                 {
                                     //chest_open_art();
                                     System.out.print("\n-You pass through the door that was once locked-\n"); 
                                 }

                            }
  
                        }
                              if(rs.getInt(6)==1)                   //if start
                            {
                               if(visited==false)
                               {
                                 System.out.print("\n-This is where it all begins, let's explore! -\n");   
                               }
                               else
                               {
                                 System.out.print("\n-You are at the start again...better find where this maze ends.-\n");   
                               
                               } 
                                                             
                            }
                             
                             if(rs.getInt(7)==1)   //if end
                            {
                               
                                 System.out.print("\n-You found the exit! 'C' to continue playing, 'E' to exit-\n");   
                                 
                                 System.out.print("Input: ");

        
                                    Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
                                 char ans = user_input.next().charAt(0);                                      //placing the user's input into a char
                                //SWITCH STATEMNT FOR USER SELECTION//
                                switch (ans) {
                                    case 'c':
                                    case 'C':
                                        get_directions(name,player_id,room); 
                                        //break;

                                    case 'e':
                                    case 'E':
                                        conn.close();
                                        System.exit(0);
                                        break;
                                    default:
                                        System.out.println("\n-Invalid Selection-");
                                }
                               
                                                             
                            }
     
                 
             
              
                             
                                                     //close con
                 
    }
              previous_room=room;
                update_visited(name,player_id,room);                 //update visted table
              get_directions(name,player_id,room);                 //see where we can go from this room
              conn.close(); 
    }
     

     
     
//GET KEY DATA
public static Integer get_key_data(Integer room_id) throws SQLException, ClassNotFoundException
     {
                String room_id_string=Integer.toString(room_id);
                String sql = "SELECT * FROM contents_tbl WHERE room_id=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                System.out.print("\n531\n");
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setInt(1, room_id);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                System.out.print("\n539\n");
                 int count=0;
                 int key=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(8)>0)
                            {
                              count++;
                              key=rs.getInt(8);
                              System.out.print(key);
                              
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return key;
                 }
                 
                 else{
                     return 0;
                 }
                 
                
                 
             
     }          
     
     
     


//GET LAST POSITION
public static Integer get_last(int name) throws SQLException, ClassNotFoundException
     {
                String room_id_string=Integer.toString(name);
                String sql = "SELECT * FROM visited_tbl WHERE player_id=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                System.out.print("\n531\n");
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, room_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                System.out.print("\n539\n");
                 int count=0;
                 int room=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(2)>0)
                            {
                              count++;
                              room=rs.getInt(3);
                              System.out.print(3);
                              
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return room;
                 }
                 
                 else{
                     return 0;
                 }
                 
                
                 
             
     }    
     
     
     
     
     

//update player's current location
     public static void update_player_location(String name,Integer room_id) throws ClassNotFoundException, SQLException
     {
            String sql = "update player_tbl set current_room = ?  where name= ?";          //creating the string we'll use to execute the update
            String myDriver = "org.gjt.mm.mysql.Driver";
            String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";    //DB connection info
            Class.forName(myDriver);
            Connection conn = DriverManager.getConnection(myUrl, "root", "password123");           //credentials to access the DB
            PreparedStatement preparedStatement = conn.prepareStatement(sql);       
            preparedStatement.setInt(1, room_id);
            preparedStatement.setString(2, name);
            Statement st = conn.createStatement();
            preparedStatement.executeUpdate();                                  //pushing the statement to the DB
            conn.close();   
     }






//get the direction(s) you can move 
    public static void get_directions(String name,Integer player_id, Integer room_id) throws ClassNotFoundException, SQLException
    {
      String room_id_string=Integer.toString(room_id);
                String sql = "SELECT * FROM rooms_tbl WHERE room_id=?";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, room_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
               
                //ints to store room ids for navigation
                int north=0;
                int south=0;
                int west=0;
                int east=0;
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(2)!=0)
                            {
                             System.out.print("\n-You can move 'n'orth -\n");
          
                             north=rs.getInt(2);
                             //System.out.print(north);
                               
                            }
                            
                            if(rs.getInt(3)!=0)
                            {
                             System.out.print("\n-You can move 's'outh -\n");
                             south=rs.getInt(3);  
                            }
                            
                            if(rs.getInt(4)!=0)
                            {
                             System.out.print("\n-You can move 'w'est -\n");
                             west=rs.getInt(4);
                               
                            }
                            
                            if(rs.getInt(5)!=0)
                            {
                             System.out.print("\n-You can move 'e'ast -\n");
                             east=rs.getInt(5);
                               
                            }
                           System.out.print("\n-'Q' to quit -\n");
                        }
                 
                 conn.close();
                 
                 
                 Scanner user_input = new Scanner(System.in);                                     //initiating scanner to accept user input
        
        System.out.print("Input: ");

        
        char ans = user_input.next().charAt(0);                                      //placing the user's input into a char
        //SWITCH STATEMNT FOR USER SELECTION//
        switch (ans) {

            //start new game
            
            case 'n':
            case 'N':
                if(north==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,north);
                }
                break;

            //continue old game
            case 's':
            case 'S':
                if(south==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,south);
                }
                break;

            //quit    
            case 'w':
            case 'W':
                if(west==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,west);
                }
                break;
                
            case 'e':
            case 'E':
                if(east==0)
                {
                  System.out.println("\n-Invalid Selection-"); 
                  get_directions(name,player_id,room_id);
                  break;
                }
                else{
                    move(name,player_id,east);
                }
                break;
                
            case 'q':
            case 'Q':
                conn.close();
                System.exit(0);
                
                
            //default statement
            default:
                System.out.println("\n-Invalid Selection-");
                get_directions(name,player_id,room_id);               
// main(null);                                                             //I don't like calling main recursively, but I couldn't get the switch to work otherwise.
            //END SWITCH//               
        } 
                 
                 
                 
                 
                 //conn.close();
                
    }
     
     
     
//update player's inventory function
     public static void update_inventory(Integer player_id,Integer room,Integer key,Integer item) throws ClassNotFoundException, SQLException
     {
                String player_id_string=Integer.toString(player_id);
                String room_string=Integer.toString(room);
                System.out.print("\n754\n");
                String sql = "INSERT INTO inventory_tbl (player_id, key_, chest, room)" + "VALUES (?,?,?,?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                if(item==4)
                {
                System.out.print("\n763\n");
                    preparedStatement.setString(1, player_id_string);
                 preparedStatement.setString(2, "1");
                 preparedStatement.setString(3, "0"); 
                 preparedStatement.setString(4, room_string); 
                 
                }
                
                if(item==5)
                {
                 System.out.print("\n772\n");
                    preparedStatement.setString(1, player_id_string);
                 preparedStatement.setString(2, "0");
                 preparedStatement.setString(3, "1"); 
                 preparedStatement.setString(4, room_string); 
                
                }
                System.out.print("\n780\n");
                preparedStatement.executeUpdate(); 
                //Statement st = conn.createStatement();
                                                                                        //pushing the INSERT command to the DB    
                conn.close();  
     }


//check for key
public static Boolean check_key(String name, Integer player_id) throws SQLException, ClassNotFoundException
     {
                String player_id_string=Integer.toString(player_id);
                String sql = "SELECT * FROM inventory_tbl WHERE player_id=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==1)
                            {
                              count++;
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return true;
                 }
                 
                 else
                 {
                     return false;
                 }
     }     
     
     
     



//check if the player has been to the current room
     public static void update_visited(String name,Integer player_id,Integer room) throws ClassNotFoundException, SQLException
     {
                String player_id_string=Integer.toString(player_id);
                String room_string=Integer.toString(room);
                String sql = "INSERT INTO visited_tbl (player_id,room_number)" + "VALUES (?,?)";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.setString(2, room_string);
                //Statement st = conn.createStatement();
                preparedStatement.executeUpdate();                                                                         //pushing the INSERT command to the DB    
                conn.close();  
     }
     

     //check if the player has been to the current room
     public static Boolean check_visited(String name, Integer player_id, Integer room_id) throws SQLException, ClassNotFoundException
     {
                String player_id_string=Integer.toString(player_id);
                String sql = "SELECT * FROM visited_tbl WHERE player_id=?";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, player_id_string);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 int count=0;
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(3)==room_id)
                            {
                              count++;
                               
                            }
                           
                        }
                 conn.close();
                 if(count>0)
                 {
                     return true;
                 }
                 
                 else
                 {
                     return false;
                 }
     }
     
     
     //method to find the starting point 
     public static void find_start(String name, Integer player_id,String level) throws SQLException, ClassNotFoundException
     {
         String sql = "select * from contents_tbl as contents, rooms_tbl as rooms where contents.start=1 and rooms.level_name=? and contents.room_id=rooms.room_id";  //creating a string we'll use to select from the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1,level);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                
                 
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                           
                            if(rs.getInt(6)==1)
                            {
                               
                                move(name,player_id,rs.getInt(2)); //call move function with the player name,player id and starting room
                               
                            }
                            
                        }
     
                 conn.close();
     }
     
     


    //method to check if the name is in the DB
      public static boolean check_name(String name) throws ClassNotFoundException, SQLException
    {
        String sql = "SELECT * FROM player_tbl WHERE name=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db2?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                int count=0;
                
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                            count++; 
                        }
                 
                
                 conn.close(); 
                 //we didn't find this username, return false so the user can make it
                 if (count==0)
                 {
                     return false;
                 }
                 
                 //this username already exists, return true and do not let them pass go
                 else
                 {
                     return true;
                 }              
    } 
      
      
      
      
//CHECK IF LEVEL IS IN LEVELS_TBL
      public static boolean check_level(String name) throws ClassNotFoundException, SQLException
    {
        String sql = "SELECT * FROM levels_tbl WHERE level_name=?";  //creating a string we'll use to insert into the DB
                String myDriver = "org.gjt.mm.mysql.Driver";
                String myUrl = "jdbc:mysql://68.188.20.101:3306/lab5_db1?autoReconnect=true&useSSL=false";                        //connection info for the DB
                Class.forName(myDriver);
                Connection conn = DriverManager.getConnection(myUrl, "root", "password123");                               //credentials to access the DB
                PreparedStatement preparedStatement = conn.prepareStatement(sql);                                          //prepared statement to insert info into table
                preparedStatement.setString(1, name);
                preparedStatement.executeQuery();
                ResultSet rs = preparedStatement.executeQuery();
                int count=0;
                
                                                                                             
                //if count is > 0, the player is in the DB. I'm sure there's a better way to do this, but Diablo season 10 just started, so I want to get done ASAP.
                 while (rs.next())                                                        
                        {                            
                            count++; 
                        }
                 
                
                 conn.close(); 
                 //we didn't find this username, return false so the user can make it
                 if (count==0)
                 {
                     return false;
                 }
                 
                 //this username already exists, return true and do not let them pass go
                 else
                 {
                     return true;
                 }              
    }       
//-------------------------------------------------//      
      
      
      
      
    
      
      



static public void key_art()
{
   
    System.out.println("\n 8 8 8 8                     ,ooo.");
    System.out.println(" 8a8 8a8                    oP   ?b");
    System.out.println("d888a888zzzzzzzzzzzzzzzzzzzz8     8b");
    System.out.println(" `\"\"^\"\"'                    ?o___oP'");
}


static public void chest_open_art()
{
   
    System.out.println("\n         __________");
    System.out.println("        /\\____;;___\\");
    System.out.println("       | /         /");
    System.out.println("       `. ())oo() .");
    System.out.println("        |\\(%()*^^()^\\");
    System.out.println("       %| |-%-------|");
    System.out.println("      % \\ | %  ))   |");
    System.out.println("      %  \\|%________|");
    System.out.println("       %%%%");
}



static public void enemy_art()
{
     System.out.println("\nX-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X");
     System.out.println("|                           ,,'``````````````',,                            |");
     System.out.println("X                        ,'`                   `',                          X");
     System.out.println("|                      ,'                         ',                        |");
     System.out.println("X                    ,'          ;       ;          ',                      X");
     System.out.println("|       (           ;             ;     ;             ;     (               |");
     System.out.println("X        )         ;              ;     ;              ;     )              X");
     System.out.println("|       (         ;                ;   ;                ;   (               |");
     System.out.println("X        )    ;   ;    ,,'```',,,   ; ;   ,,,'```',,    ;   ;               X");
     System.out.println("|       (    ; ',;   '`          `',   ,'`          `'   ;,' ;              |");
     System.out.println("X        )  ; ;`,`',  _--~~~~--__   ' '   __--~~~~--_  ,'`,'; ;     )       X");
     System.out.println("|     (    ; `,' ; :  /       \\~~-___-~~/       \\  : ; ',' ;     (        |");
     System.out.println("X      )   )',  ;   -_\\  o    /  '   '  \\    o  /_-   ;  ,'       )   (   X");
     System.out.println("| (     (   (   `;      ~-____--~'       '~--____-~      ;'  )     (     )  |");
     System.out.println("X  )     )   )   ;            ,`;,,,   ,,,;',            ;  (       )   (   X");
     System.out.println("| (     (   (  .  ;        ,'`  (__ '_' __)  `',        ;  . )     (     )  |");
     System.out.println("X  )   \\/ ,\".). ';    ,'`        ~~ ~~        `',    ;  .(.\", \\/  )   ( X");
     System.out.println("| (   , ,'|// / (/ ,;  '        _--~~-~~--_        '  ;, \\)    \\|', ,  )  |");
     System.out.println("X ,), \\/ \\|  \\\\,/  ;;       ,; |_| | |_| ;,       ;;  \\,//  |/ \\/ , , X");
     System.out.println("|                            ;_| : `~'~' : |_;                              |");
     System.out.println("X#(,'  )  #\\ \\##/)#;      :  `\\/       \\/   :     ;#(\\##/ /#///(  ',)#,X");
     System.out.println("|| ) | \\ |/ /#/ |#( \\; ;      :          ;     ; ;/ )#| \\#\\ \\| / | ( |) |");
     System.out.println("X\\ |.\\\\ |\\_/#| /#),,`     ;./\\_     _/\\.;    ; `,,(#\\ |#\\_/| //.| / ,X");
     System.out.println("| \\\\_/# |#\\##/,,'`       ;   ~~--|~|~|--~~  ;       `',,\\##/#| #\\_// \\/|");
     System.out.println("X  ##/#  #,,'`            ;        ~~~~~        ;            `',,#  #\\##  //X");
     System.out.println("|####@,,'`                 `',               ,'`                 `',,@####| |");
     System.out.println("X#,,'`                        `',         ,'`                        `',,###X");
     System.out.println("|'                               ~~-----~~                               `' |");
     System.out.println("X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X-X");
     
}


}
