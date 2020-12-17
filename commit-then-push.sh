#!/bin/bash

git add .

git commit -m "$1"

git pull origin 5.0
git push origin 5.0
