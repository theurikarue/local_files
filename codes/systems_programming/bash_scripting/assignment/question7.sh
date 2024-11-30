#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question7: Department Chairman of Computing has heard about your Unix shell scripting Prowess in creating mail merge service, he wants your services to invite students to a webinar hosted by JhubAfrica. The department wants to send the invitation letter below to a webinar addressed to each student personally.

if [ $# -ne 1 ]; then
    echo "Usage: $0 <list_file>"
    exit 1
fi

list=$1

# Check if the file exists
if [ ! -f "$list" ]; then
    echo "Error: The file $list does not exist"
    exit 1
fi

# Webinar details
WEBINAR_DATE="Friday, 29th November"
WEBINAR_TIME="5:00 P.M."
ZOOM_LINK="https://us05web.zoom.us/s/81685224614#success"
YOUTUBE_LINK="https://youtu.be/ONVTA7LKMIs"

# Loop through each line in the file
while IFS=, read -r name email; do
    name=$(echo $name | xargs)  # Remove leading/trailing spaces
    email=$(echo $email | xargs)  # Remove leading/trailing spaces

    # Ensure both name and email are not empty
    if [ -n "$name" ] && [ -n "$email" ]; then
        invitation="Dear $name,\n\n\
        Inviting you as our computing student to our 21st Open Webinar on skills optimization by jhubAfrica scheduled for $WEBINAR_DATE at $WEBINAR_TIME.\n\n\
        The Zoom link for joining in on Friday is as given below:\n\
        $ZOOM_LINK\n\n\
        We shall also broadcast the webinar on our YouTube channel.\n\
        YouTube link: $YOUTUBE_LINK\n\n\
        Best regards,\n\
        Department of Computing\n"

        # Send the email using mail command (ensure mailutils is installed)
        echo -e "$invitation" | mail -s "Invitation to 21st Open Webinar" "$email"
        echo "Invitation sent to $name <$email>."
    else
        echo "Skipping invalid line: $name, $email"
    fi
done < "$list"

echo "Mail merge complete."
