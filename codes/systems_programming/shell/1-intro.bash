#!/bin/bash

# to know the the different bashes you can use this command - cat /etc/shells
# in my case the output is as shown below:
: '
cat /etc/shells

/bin/sh
/usr/bin/sh
/bin/bash
/usr/bin/bash
/bin/rbash
/usr/bin/rbash
/bin/dash
/usr/bin/dash
/usr/bin/pwsh
/opt/microsoft/powershell/7/pwsh
/usr/bin/screen
/usr/bin/tmux
/bin/zsh
/usr/bin/zsh
'

# for the bash paths you can use : which bash
# in my case the output is as shown below:
# /usr/bin/bash

: '
# The first line of the script is called the shebang line #!/usr/bin/bash. The shebang line is used to tell the system the path of the interpreter that should be used to execute the script

to make the file executable use the following command 
chmod +x 1-intro.bash
'