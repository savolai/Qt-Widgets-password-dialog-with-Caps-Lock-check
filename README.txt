Password dialog intended for less security critical applications. 

* Checks password on each keystroke
* Enables OK button when password is correct
* Notifies user if caps lock is on 
  * but only when user hasn't already entered correct password

Todo: only trigger password check from the event handler, the type handler of the lineEdit is likely unnecessary.
