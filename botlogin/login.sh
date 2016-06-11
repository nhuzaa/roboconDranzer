#!/bin/bash
USERNAME=pi
HOSTNAME=192.168.0.104
PASS="raspberry"

ssh -l ${USERNAME} ${HOSTNAME} <<  ${PASS} ;

ls;



