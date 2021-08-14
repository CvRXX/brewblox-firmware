#!/bin/sh

REPO_ROOT="$(git rev-parse --show-toplevel)"
cp "$REPO_ROOT/hooks/pre-push" "$REPO_ROOT"/.git/hooks