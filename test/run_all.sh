#!/bin/sh
TESTDIR=$(dirname $0)

function grepin() {
  grep -oP '(?<=^> ).*$'
}

function grepout() {
  grep -oP '(?<=^< ).*$'
}

for io in $TESTDIR/*.io; do
  prog=$(head -n1 $io | grepin)

  # print header/title
  tput bold
  printf "%-$[$(tput cols)/2-3]s   %s\n" $io.run \
    "cat $io | grepin | $prog"
  tput sgr0

  # copy input lines and write output lines to run file
  cat $io | grep '^> ' > $io.run
  tail -n +2 $io | grepin | $prog | sed 's/^/< /' >> $io.run

  # compare run file with expected file, ignoring input
  output=$(sdiff --width=$(tput cols) \
    --ignore-matching-lines='^> ' \
    $io $io.run)
  status=$?

  echo "$output" | colordiff
  [ $status -eq 0 ] || exit $status
done

