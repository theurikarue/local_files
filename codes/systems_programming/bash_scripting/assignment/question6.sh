#!/bin/bash
# NAME : THEURI BONFACE KARUE
# REG_NO : SCT211-0573/2022
# Question6: . Write a bash Script that scan network for hosts attached to an IP address. The script should show if the host is up indicating Yes if up.

check_host() {
    local host=$1
    if ping -c 1 -W 1 "$host" &> /dev/null; then
        echo "$host is up: Yes"
    else
        echo "$host is up: No"
    fi
}

echo "Enter the network range to scan (e.g., 192.168.1.0/24):"
read -r network

# Loop through the IP range in the network
for ip in $(seq 1 254); do
    host="${network%.*}.$ip"
    check_host "$host"
done
