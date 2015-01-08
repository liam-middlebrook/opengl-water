#!/bin/sh

# Check What Distro we're on
DISTRO="$(lsb_release -d)"

if [[ $DISTRO == *"Debian"* ]]
then
        # Install Dependencies for Debian
        echo "Debian Detected"

elif [[ $DISTRO == *"Fedora"* ]]
then
        # Install Dependencies for Fedora
        echo "Fedora Detected"
        sudo yum install glew-devel freeimage-devel glfw-devel glm-devel

else
        echo "Your distro is currently unsupported by this configure.sh file"
fi

