@ECHO OFF
echo "Automatic GIT update"
echo "Adding GIT FILES ALL"
git add .
echo "Commiting"
git commit -m %1%
echo "Git push"
git push
