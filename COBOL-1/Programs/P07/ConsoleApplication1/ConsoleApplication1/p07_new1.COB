       identification division.
       program-id. TRIG-CALC.
       author. Alan Thomas.
       date-compiled. 10/26/2015.
      *function: Accept and compute/display SINE,COSINE & TANGENT
      *input files None
      *output files None
      *printer ouput None



       data division.
       working-storage section.
       01 p-day-in  pic 9(9).
       01 p-dow-out pic x(3).
       01 p-genter  pic 9(8).

       01 P-DOW    PIC 9(9).
       01 D-ENTER-DATE-DOW PIC X(3).
       01 SWITCH PIC X VALUE 'N'.
       01 COUNTER PIC 9(3) VALUE 0.


       01 CURRENT-DATE-AND-TIME.
           05 CD-YEAR          PIC 9999.
           05 CD-MONTH         PIC 99.
           05 CD-DAY           PIC 99.
           05 CD-DAY-OF-WEEK PIC 9(1).
           05 CD-DAY-NAME     PIC X(9).

        01 enter-date pic 9(8).
        01 enter-date-x redefines enter-date.
           05 yyyy pic 9(4).
           05 mm pic 9(2).
           05 dd pic 9(2).


       01 WORK-DATE PIC 9(8).
       01  work-date-X REDEFINES WORK-DATE.
           05 yyyy pic 9(4).
           05 mm pic 9(2).
           05 dd pic 9(2).


       procedure division.

       000-MAIN.
           MOVE FUNCTION CURRENT-DATE TO CURRENT-DATE-AND-TIME.
           DISPLAY "TODAY IS: ", CD-MONTH, "/" , CD-DAY , "/" , CD-YEAR.

           PERFORM 100-GET-DATE.
           PERFORM 120-CONVERT-GREGORIAN.
           move p-genter to p-day-in.
           move p-dow-out to D-ENTER-DATE-DOW.
           PERFORM 200-SET-DOW.
           STOP RUN.




      *-BEGIN CODE TO ACCEPT AND DISPLAY USER INPUT-
       100-GET-DATE.
           DISPLAY "YYYYMMDD - Enter date (after 12/31/1601): ".  *>line to accept user date
           accept enter-date.
           move corr enter-date-x to work-date-X.
           MOVE work-date-X TO P-DOW.

       120-CONVERT-GREGORIAN.
           MOVE FUNCTION INTEGER-OF-DATE (enter-date) TO p-genter.

       200-SET-DOW.
           MOVE SPACES TO P-DOW-OUT.
               COMPUTE P-DOW = FUNCTION REM (p-day-in,7)
               EVALUATE p-dow
                   WHEN 1 MOVE "Mon" TO p-dow-out
                   WHEN 2 MOVE "Tue" TO p-dow-out
                   WHEN 3 MOVE "Wed" TO p-dow-out
                   WHEN 4 MOVE "Thu" TO p-dow-out
                   WHEN 5 MOVE "Fri" TO p-dow-out
                   WHEN 6 MOVE "Sat" TO p-dow-out
                   WHEN 0 MOVE "Sun" TO p-dow-out
           END-EVALUATE.
           DISPLAY "DATE ENTERED: " p-dow-out , p-day-in.



           MOVE SPACES TO P-DOW-OUT.
               SUBTRACT 100 FROM p-day-in
               COMPUTE P-DOW = FUNCTION REM (p-day-in,7)
               EVALUATE p-dow
                   WHEN 1 MOVE "Mon" TO p-dow-out
                   WHEN 2 MOVE "Tue" TO p-dow-out
                   WHEN 3 MOVE "Wed" TO p-dow-out
                   WHEN 4 MOVE "Thu" TO p-dow-out
                   WHEN 5 MOVE "Fri" TO p-dow-out
                   WHEN 6 MOVE "Sat" TO p-dow-out
                   WHEN 0 MOVE "Sun" TO p-dow-out
           END-EVALUATE.
           DISPLAY p-dow-out , p-day-in , " THRU " , WITH NO ADVANCING.


           MOVE SPACES TO P-DOW-OUT.
               ADD 200 TO p-day-in
               COMPUTE P-DOW = FUNCTION REM (p-day-in,7)
               EVALUATE p-dow
                   WHEN 1 MOVE "Mon" TO p-dow-out
                   WHEN 2 MOVE "Tue" TO p-dow-out
                   WHEN 3 MOVE "Wed" TO p-dow-out
                   WHEN 4 MOVE "Thu" TO p-dow-out
                   WHEN 5 MOVE "Fri" TO p-dow-out
                   WHEN 6 MOVE "Sat" TO p-dow-out
                   WHEN 0 MOVE "Sun" TO p-dow-out
           END-EVALUATE.
           DISPLAY p-dow-out , p-day-in.











       end program TRIG-CALC.
