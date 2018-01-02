Password dialog example

This is perhaps for less security critical applications, i.e. for confirming the user indeed intends to do something, in a situation where no undo is available.

More security critical applications may want a separate button for checking password, and limiting the number of tries. This makes brute forcing more difficult.

* Checks password on each keystroke
* Enables OK button when password is correct
* Notifies user if caps lock is on 
  * but only when user hasn't already entered correct password

Todo: only trigger password check from the event handler, the type handler of the lineEdit is likely unnecessary.
