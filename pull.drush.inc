<?php

/**
 * @file
 *   Drush shortcut to git pull, database update, features revert and clear cache in one command.
 *
 *   Installation:
 *   You can copy this file to any of the following
 *   1. A .drush folder in your HOME folder.
 *   2. Anywhere in a folder tree below an active module on your site.
 *   3. /usr/share/drush/commands (configurable)
 *   4. In an arbitrary folder specified with the --include option.
 *   5. Drupal's sites/all/drush folder.
 */

/**
 * Implementation of hook_drush_command().
 */
function pull_drush_command() {
  $items = array();

  $items['git-pull'] = array(
    'description' => "Makes git pull, updates db, reverts features and clears caches.",
    'aliases' => array('pull'),
    'bootstrap' => DRUSH_BOOTSTRAP_DRUSH, // No bootstrap at all.
  );

  return $items;
}

/**
 * Run command
 */
function drush_pull_git_pull() {
  drush_shell_exec('git pull');
  drush_invoke_process('@self', 'updatedb');
  drush_invoke_process('@self', 'fra');
  drush_invoke_process('@self', 'cc', array('all'));
}

