externalCommands.o: externalCommands.c strTok.h
strTok.o: strTok.c strTok.h history.h
rmwhite.o: rmwhite.c
changeDirectory.o: changeDirectory.c history.h strTok.h
cwd.o: cwd.c history.h
smash.o: smash.c history.h commands.h rmwhite.h externalCommands.h
commands.o: commands.c history.h strTok.h changeDirectory.h cwd.h \
 externalCommands.h rmwhite.h
history.o: history.c smash.h history.h
