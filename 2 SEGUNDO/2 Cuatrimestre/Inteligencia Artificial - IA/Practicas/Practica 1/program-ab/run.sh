# Run bot
rm -fr bots/mybot/aimlif/*
java -cp lib/Ab.jar Main bot=mybot action=aiml2csv trace=false morph=false
