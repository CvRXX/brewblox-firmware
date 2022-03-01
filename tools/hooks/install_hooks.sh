#!/bin/sh

REPO_ROOT="$(git rev-parse --show-toplevel)"
cp "$REPO_ROOT/tools/hooks/pre-push" "$REPO_ROOT"/.git/hooks
