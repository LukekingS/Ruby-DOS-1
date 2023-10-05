#!/usr/bin/env bash
. ./scripts/impl_var.sh

echo "COM: "
read COM
avrdude -c $1 -P ${COM} -b $2 -p $3 -D -U flash:w:./${BIN_DIR}/fw.hex:i