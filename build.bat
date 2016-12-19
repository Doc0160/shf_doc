@echo off
git add *
git commit -m "Automatic: %time% %date%"
git push
