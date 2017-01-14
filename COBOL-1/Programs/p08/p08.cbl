       IDENTIFICATION DIVISION.
       program-id. FLIPPER.

       author. Alan Thomas.
       date-compiled. 11/13/2015.
      *THIS PROGRAM IS CODED TO ACCEPT AND EDIT AN INDIVIDUALS
      *FULL NAME, STRING SAID NAME THAN UNSTRING.

       data division.
       working-storage section.

          01 NAMES.
           05 FIRST-NAME  PIC X(10).
           05 MIDDLE-NAME PIC X(10).
           05 LAST-NAME   PIC X(15).

       01 FULL-NAME       PIC X(35).

       01 SWITCH          PIC X VALUE "Y".

       procedure division.
       000-MAIN.
           PERFORM 100-ACCEPTNAME.
           PERFORM 120-UPPERCASE.
           PERFORM 130-LOWERCASE.
           PERFORM 140-STRINGPROCESS.

           DISPLAY "YOUR NAME: " , FULL-NAME.
           PERFORM 150-REPLACE.
           DISPLAY "YOUR EDITED NAME: " , FULL-NAME WITH NO ADVANCING.
           PERFORM 155-UNREPLACE.
           PERFORM 160-UNSTRING.
           DISPLAY "UNSTRING: " , FIRST-NAME , MIDDLE-NAME, LAST-NAME
               WITH NO ADVANCING.
           PERFORM 999-EXIT.




       100-ACCEPTNAME.
           DISPLAY "ENTER FIRST NAME: ".
           ACCEPT FIRST-NAME.

           DISPLAY "ENTER MIDDLE NAME: ".
           ACCEPT MIDDLE-NAME.

           DISPLAY "ENTER LAST NAME: ".
           ACCEPT LAST-NAME.

      *---CHANGING ALL FIRST DIGITS IN NAMES TO UPPER---
       120-UPPERCASE.
        MOVE FUNCTION UPPER-CASE (FIRST-NAME(1:1)) TO FIRST-NAME(1:1).
        MOVE FUNCTION UPPER-CASE (MIDDLE-NAME(1:1)) TO MIDDLE-NAME(1:1).
        MOVE FUNCTION UPPER-CASE (LAST-NAME(1:1)) TO LAST-NAME(1:1).

       130-LOWERCASE.
        MOVE FUNCTION LOWER-CASE (FIRST-NAME(2:)) TO FIRST-NAME(2:).
        MOVE FUNCTION LOWER-CASE (MIDDLE-NAME(2:)) TO MIDDLE-NAME(2:).
        MOVE FUNCTION LOWER-CASE (LAST-NAME(2:)) TO LAST-NAME(2:).



      *---COMBINING ALL NAME FIELDS INTO FULL-NAME---
       140-STRINGPROCESS.
          MOVE SPACE TO FULL-NAME.
          STRING FIRST-NAME DELIMITED BY " "

                 MIDDLE-NAME DELIMITED BY SPACE

                 LAST-NAME DELIMITED BY SPACE
                 INTO FULL-NAME.



       150-REPLACE.
              INSPECT FULL-NAME REPLACING
              ALL "A" BY "Z".
              INSPECT FULL-NAME REPLACING
              ALL "a" BY "z".
              INSPECT FULL-NAME REPLACING
              ALL "S" BY "X".
              INSPECT FULL-NAME REPLACING
              ALL "s" BY "x".

       155-UNREPLACE.
              INSPECT FULL-NAME REPLACING
              ALL "Z" BY "A".
              INSPECT FULL-NAME REPLACING
              ALL "z" BY "a".
              INSPECT FULL-NAME REPLACING
              ALL "X" BY "S".
              INSPECT FULL-NAME REPLACING
              ALL "x" BY "s".

       160-UNSTRING.
           UNSTRING FULL-NAME DELIMITED BY ALL " "
                   INTO FIRST-NAME MIDDLE-NAME LAST-NAME.


       999-EXIT.
           DISPLAY "CONTINUE(N/Y): ".
           ACCEPT SWITCH.

           IF SWITCH = "N" OR "n"
                      STOP RUN
           ELSE IF SWITCH = "Y" OR "y"
               PERFORM 000-MAIN
           ELSE
               DISPLAY "INVALID RESPONSE"
               PERFORM 999-EXIT.


       end program FLIPPER.
